# Part I
from functools import cache


def wire_assembly(data):
    parts = {}
    ops_dict = {"AND": "&", "OR": "|", "LSHIFT": "<<", "RSHIFT": ">>", "NOT": "~"}

    # This creates the circuit of signal to wires using a dictionary
    for datum in data.split("\n"):
        left, right = datum.split('->')
        parts[right.strip()] = left.strip()

    @cache
    def find_signal(wire):

        if wire.isnumeric():
            return int(wire)
        else:
            # Check if the len is 1
            if len(parts[wire].split()) == 1:
                return find_signal(parts[wire])


            # Check if the len is 2
            elif len(parts[wire].split()) == 2:
                ops, operand = parts[wire].split()
                temp_result = eval(f"{ops_dict[ops]} {find_signal(operand)}")

            # Check if the len is 3
            elif len(parts[wire].split()) == 3:
                operand1, ops, operand2 = parts[wire].split()
                temp_result = eval(f"{find_signal(operand1)} {ops_dict[ops]} {find_signal(operand2)}")

            # Check if the len is 3
        return str(temp_result) if temp_result >= 0 else str((-(int(temp_result) + 1) - 65535) * -1)

    # Part I
    # return find_signal('a')

    # Part II
    parts['b'] = find_signal('a')
    find_signal.cache_clear()
    return find_signal('a')
