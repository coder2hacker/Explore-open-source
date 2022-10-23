def santa_movement(floors):
    count = 0
    for i in floors:
        if i == '(':
            count += 1
        else:
            count -= 1
    return count


def santa_movement_II(floors):
    count = 0
    for index, floor in enumerate(floors,start=1):
        if floor == '(':
            count += 1
        else:
            count -= 1
            if count == -1: return index
    return count