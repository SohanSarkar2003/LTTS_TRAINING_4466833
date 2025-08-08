def xor_strings(s, t):
    result = ""
    for i in range(len(s)):
        if bool(1-int(s[i])^int(t[i])):
            result += '0';
        else:
            result += '1';

    return result

s = input()
t = input()
print(xor_strings(s, t))