import re
import string

def lookandsay(limit, sequence = 1):

    if limit > 1:

        return lookandsay(limit-1, "".join([str(len(match.group()))+match.group()[0] for matchNum, match in enumerate(re.finditer(r"(\w)\1*", str(sequence)))]))

    else:

        return sequence


for i in range(1,44):
    print("\"{} {:.6f}\\n\",".format(len(str(lookandsay(i))),len(str(lookandsay(i-1)))/len(str(lookandsay(i)))))