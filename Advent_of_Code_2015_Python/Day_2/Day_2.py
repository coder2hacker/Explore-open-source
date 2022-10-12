def sq_feet_of_wrapping_paper(input_data):
    def find_wrapper_feet(data):
        l, w, h = map(lambda x: int(x), data.split("x"))
        surface_area = 2 * ((l * w) + (w * h) + (h * l))
        feet_of_slack = min((l * w), (w * h), (h * l))
        return surface_area + feet_of_slack

    return sum(map(lambda x: find_wrapper_feet(x),
                   input_data.split("\n")))


def total_feet_of_ribbon(input_data):
    def ribbon_plus_bow(data):
        l, w, h = map(lambda x: int(x), data.split("x"))
        bow = l * w * h
        sorted_dimensions = sorted([l, w, h])
        min_1, min_2 = sorted_dimensions[0], sorted_dimensions[1]
        ribbon = min_1 + min_1 + min_2 + min_2

        return bow + ribbon

    return sum(map(lambda x: ribbon_plus_bow(x),
                   input_data.split("\n")))