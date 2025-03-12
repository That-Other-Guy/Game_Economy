#include "GameCargo.hpp"
#include <sstream>

std::pair<Game_Economy::CargoReturn, std::string>
    MoveBulkCargo(
        Game_Economy::Objects::BulkCargo& _source, 
        Game_Economy::Objects::BulkCargo& _destination, 
        float _transfer_volume, bool _clean_src = false, bool _ext_string = false
    )
{
    Game_Economy::CargoReturn cargo_return;
    std::ostringstream stream;
    auto src_cargo = _source.GetCargoType();
    auto dst_cargo = _destination.GetCargoType();

    stream << "Moving " << src_cargo.PrintCargoName() << " from\n";
    if (_ext_string)
        stream << _source.GetBriefDetails() << "\nto\n"
        << _destination.GetBriefDetails();
    else
        stream << "(" << std::to_string(_source.GetUniqueID()) << ") to ("
        << std::to_string(_destination.GetUniqueID()) << ")\n";

    // Ensure Cargo Matched.
    if (!(src_cargo == dst_cargo))
    {        
        stream << "Attempting to repurpose the destination container.\n";
        cargo_return = _destination.CleanBulkCargo();
        if (!cargo_return.Success())
        {
            cargo_return += Game_Economy::CargoReturn_T::CargoTypeMismatch;
            stream << "Could not prepare the destination container:\n"
                << cargo_return.Print();
            return { cargo_return, stream.str() };
        }
        cargo_return = _destination.AssignCargoType(src_cargo.GetCargoType());
        if (cargo_return.Success())
        {
            cargo_return += Game_Economy::CargoReturn_T::CargoTypeMismatch;
            stream << "Could not prepare the destination container:\n"
                << cargo_return.Print();
            return { cargo_return, stream.str() };
        }
    }
    // Cargo determined to be matched.
    auto dst_cap = _destination.GetVolume();
    auto src_sup = _source.GetVolume();
    if (dst_cap.remaining_litres < _transfer_volume)
        // Not enough space at destination.
    {
        stream << "The destination container does not have the capacity.";
        cargo_return += Game_Economy::CargoReturn_T::VolumeExceeded;
    }
    if (src_sup.loaded_litres < _transfer_volume)
        // Not enough available at source.
    {
        stream << "The source container does not enough.";
        cargo_return += Game_Economy::CargoReturn_T::InsufficientAvailable;
    }
    if (cargo_return.Success())
    {
        stream << "Successfully moved " 
            << Game_Math::Utilities::PrintFloat2(_transfer_volume)
            << "L";
        _source.Take(_transfer_volume);
        _destination.Add(_transfer_volume);
        src_sup = _source.GetVolume();
        if (src_sup.loaded_litres)

        return { cargo_return, stream.str() };
    }
    if (_source)



    return Game_Economy::CargoReturn();
}
