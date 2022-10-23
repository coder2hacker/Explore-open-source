import hashlib

# Part 1
def stock_stuffer(data):
    num = 0
    while True:
        if hashlib.md5(bytes(data + str(num), 'utf8')).hexdigest().startswith("00000"):
            return num
        else:
            num += 1

# Part 2
def stock_stuffer_II(data):
    num = 0
    while True:
        if hashlib.md5(bytes(data + str(num), 'utf8')).hexdigest().startswith("000000"):
            return num
        else:
            num += 1