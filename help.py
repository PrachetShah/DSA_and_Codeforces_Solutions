def formatter(table, section='A'):
    cols, vals = [], []

    for point in table:
        if len(point)>0:
            formatted = point.strip().split(" ")
            for data in formatted:
                if section in data:
                    cols.append(data)
                else:
                    vals.append(data)
    print("Formatted")
    map = {}
    for index, val in enumerate(cols):
        print(cols[index], "|", vals[index], end=" | ")
        map[int(cols[index].replace(section, ""))] = vals[index]
        if (index+1)%5==0:
            print()
    print()
    new = sorted(map.items(), key= lambda item:item[0])
    print(new)
    return new

def calc(val):
    one = round(val*0.45, 2)
    # print(one)
    two = round(one*0.18, 2)
    # print(two)
    three = two + one
    # print(three)
    four = round(three + three*0.03, 2)
    # print(four)
    five = four + four*0.2
    # print(round(five))
    return round(five)

table = table3.split("\n")
final = []
print(table)

calc(137)
i=0
section = 'C'
new = formatter(table, section)

rows = [['Size', 'Rate', 'Price']]
for key, value in new:
    rows.append([f'{section}{key}', value.replace("$", ""), calc(float(value.replace("$", "")))])
    # print(f'A{key}', value.replace("$", ""), calc(float(value.replace("$", ""))))
    # i += 1
    # if i==5:
    #     break

import pandas as pd
df = pd.DataFrame(rows)
df.to_csv(f"{section}Col.csv", index=False, header=False)