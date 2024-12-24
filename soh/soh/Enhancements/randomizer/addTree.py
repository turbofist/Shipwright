import os

def add_to_location_list(file_path, values):
    pattern = (
        "locationTable[{0}] = Location::Tree({0}, RCQUEST_BOTH, {1}, {2}, TWO_ACTOR_PARAMS({3}, {4}), \"{5}\", \"{6}\", RHT_TREE_MARKET, RG_GREEN_RUPEE, "
        "SpoilerCollectionCheck::RandomizerInf({7}));\n"
    ).format(*values)

    update_file(file_path, "//CUSTOM ADD HERE", pattern)

def add_to_randomizer(file_path, rc_name, rand_name):
    pattern = f"    {{ {rc_name}, {rand_name} }},\n"
    update_file(file_path, "//CUSTOM ADD HERE", pattern)

def add_to_debug_save_editor(file_path, rand_name):
    pattern = f"    {{ {rand_name}, \"{rand_name}\" }},\n"
    update_file(file_path, "//CUSTOM ADD HERE", pattern)

def add_to_randomizer_types(file_path, rc_name):
    pattern = f"    {rc_name},\n"
    update_file(file_path, "//CUSTOM ADD HERE", pattern)

def add_to_randomizer_inf(file_path, rand_name):
    pattern = f"    {rand_name},\n"
    update_file(file_path, "//CUSTOM ADD HERE", pattern)

def generate_rand_name(rc_name):
    return rc_name.replace("RC_", "RAND_INF_")

def update_file(file_path, marker, new_content):
    if not os.path.exists(file_path):
        print(f"File not found: {file_path}")
        return

    with open(file_path, "r") as file:
        lines = file.readlines()

    with open(file_path, "w") as file:
        for line in lines:
            file.write(line)
            if marker in line:
                file.write(new_content)
                print(f"Added content to {file_path} after marker '{marker}'.")

def main():
    location_list_file = "location_list.cpp"
    randomizer_file = "randomizer.cpp"
    debug_save_editor_file = "../debugger/debugSaveEditor.h"
    randomizer_types_file = "randomizerTypes.h"
    randomizer_inf_file = "randomizer_inf.h"

    while True:
        print("Enter the details for the new entry (or type 'exit' to quit):")

        rc_name = input("RC Name: ").strip()
        if rc_name.lower() == 'exit':
            break

        area_name = input("Area Name: ").strip()
        scene_name = input("Scene Name: ").strip()
        actor_param1 = input("Actor Param 1: ").strip()
        actor_param2 = input("Actor Param 2: ").strip()
        description = input("Description: ").strip()
        short_name = input("Short Name: ").strip()

        rand_name = generate_rand_name(rc_name)

        # Add to location_list.cpp
        add_to_location_list(
            location_list_file,
            [rc_name, area_name, scene_name, actor_param1, actor_param2, description, short_name, rand_name],
        )

        # Add to randomizer.cpp
        add_to_randomizer(randomizer_file, rc_name, rand_name)

        # Add to debugSaveEditor.h
        add_to_debug_save_editor(debug_save_editor_file, rand_name)

        # Add to randomizerTypes.h
        add_to_randomizer_types(randomizer_types_file, rc_name)

        # Add to randomizer_inf.h
        add_to_randomizer_inf(randomizer_inf_file, rand_name)

        print("Entry added successfully!\n")

if __name__ == "__main__":
    main()
