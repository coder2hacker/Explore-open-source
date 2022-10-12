# Part 1
def santa_delivering(directions):
    coords = (0, 0)
    coords_list = [coords]
    for direction in directions:
        if direction == "^":
            coords = (coords[0], coords[1] + 1)
        elif direction == "v":
            coords = (coords[0], coords[1] - 1)
        elif direction == "<":
            coords = (coords[0] - 1, coords[1])
        elif direction == ">":
            coords = (coords[0] + 1, coords[1])
        coords_list.append(coords)
    return len(set(coords_list))


# Part 2
def santa_deliveringII(directions):
    santa_coords, robo_coords = (0, 0), (0, 0)
    coords_list = [santa_coords,robo_coords]
    for index,direction in enumerate(directions):
        if direction == "^":
            if not index%2:
                santa_coords = (santa_coords[0], santa_coords[1] + 1)
            else:
                robo_coords = (robo_coords[0], robo_coords[1] + 1)
        elif direction == "v":
            if not index%2:
                santa_coords = (santa_coords[0], santa_coords[1] - 1)
            else:
                robo_coords = (robo_coords[0], robo_coords[1] - 1)
        elif direction == "<":
            if not index%2:
                santa_coords = (santa_coords[0] - 1, santa_coords[1])
            else:
                robo_coords = (robo_coords[0] - 1, robo_coords[1])
        elif direction == ">":
            if not index%2:
                santa_coords = (santa_coords[0] + 1, santa_coords[1])
            else:
                robo_coords = (robo_coords[0] + 1, robo_coords[1])
        coords_list.append(santa_coords)
        coords_list.append(robo_coords)
    return len(set(coords_list))