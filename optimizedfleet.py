class Vehicle:
    def __init__(self, reg_no, vehicle_type, truck_capacity, curr_weight, fuel_cost_unloaded, fuel_cost_loaded):
        self.reg_no = reg_no
        self.vehicle_type = vehicle_type
        self.truck_capacity = truck_capacity
        self.curr_weight = curr_weight
        self.fuel_cost_unloaded = fuel_cost_unloaded
        self.fuel_cost_loaded = fuel_cost_loaded

def prepare_fleets(vehicles, target_weight):
    # Find the upper bound
    upper_bound = target_weight
    for vehicle in reversed(eligible_vehicles):
        if(vehicle.truck_capacity>target_weight):
            upper_bound=vehicle.truck_capacity
        else:
            break

    # Filter vehicles with capacities within the target range
    eligible_vehicles = [vehicle for vehicle in vehicles if 0 <= vehicle.truck_capacity <= upper_bound]

    # Get the total sum of the capacities of the eligible vehicles
    total_capacity = sum(vehicle.truck_capacity for vehicle in eligible_vehicles)

    # First Fleet: Start from the beginning and erase vehicles until total capacity is just larger or equal to the target
    first_fleet = []
    remaining_capacity = total_capacity
    for vehicle in eligible_vehicles:
        if remaining_capacity - vehicle.truck_capacity >= target_weight:
            remaining_capacity -= vehicle.truck_capacity
            first_fleet.append(vehicle)
        else:
            break

    # Second Fleet: Start from the end and erase vehicles until total capacity is just larger or equal to the target
    second_fleet = []
    remaining_capacity = total_capacity
    for vehicle in reversed(eligible_vehicles):
        if remaining_capacity - vehicle.truck_capacity >= target_weight:
            remaining_capacity -= vehicle.truck_capacity
            second_fleet.append(vehicle)
        else:
            break

    # Calculate total cost and size of both fleets
    first_fleet_cost = sum(vehicle.fuel_cost_unloaded for vehicle in first_fleet)
    second_fleet_cost = sum(vehicle.fuel_cost_unloaded for vehicle in second_fleet)
    first_fleet_size = len(first_fleet)
    second_fleet_size = len(second_fleet)

    # Return the fleet with minimum cost and size
    if first_fleet_cost < second_fleet_cost or (first_fleet_cost == second_fleet_cost and first_fleet_size < second_fleet_size):
        return first_fleet
    else:
        return second_fleet

# Example usage:
vehicles = [
    Vehicle("ABC123", "Truck", 5000, 3000, 50, 60),
    Vehicle("DEF456", "Van", 3000, 2000, 40, 50),
    Vehicle("GHI789", "Truck", 6000, 4000, 60, 70),
    Vehicle("JKL012", "Van", 4000, 2500, 45, 55),
]

target_weight = 4500
final_fleet = prepare_fleets(vehicles, target_weight)

print("Final Fleet:")
for vehicle in final_fleet:
    print(vehicle.reg_no)
