# Part 1
def is_naughty_or_nice(input_data):
    input_data = input_data.split("\n")

    def nice_string(s):

        # Criteria 1
        def vowel_count_criteria():
            vowel_count = 0
            for i in s:
                if i in ("aeiou"):
                    vowel_count += 1
            if vowel_count >= 3:
                return True
            return False

        # Criteria 2
        def appear_twice():
            for index in range(len(s) + 1):
                if index + 1 < len(s) and s[index] == s[index + 1]:
                    return True
            return False

        # Criteria 3
        def exclusions():
            return "ab" in s or "cd" in s or "pq" in s or "xy" in s

        return vowel_count_criteria() and appear_twice() and not exclusions()

    return len(list(filter(lambda data: nice_string(data), input_data)))


# Part 2
def is_naughty_or_nice_II(input_data):
    input_data = input_data.split("\n")

    def nice_string_II(s):
        # Criteria 1
        def pair_without_overlap():
            return sum([1 for index, element in enumerate(s)
                        if index + 1 < len(s)
                        and element + s[index + 1]
                        in s[index + 2:]]) > 0

        # Criteria 2
        def repeat_btn_them():
            return sum([1 for index, element in enumerate(s)
                        if index + 1 < len(s)
                        and index != 0
                        and s[index - 1] == s[index + 1]]) > 0

        return pair_without_overlap() and repeat_btn_them()

    return len(list(filter(lambda data: nice_string_II(data), input_data)))