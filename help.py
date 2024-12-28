table1 = '''
A15
137.00
A39
224.00
A63
315.00
A87
419.00
A120
646.00
A16
138.00
A40
229.00
A64
315.00
A88
440.00
A124
674.00
A17
145.00
A41
234.00
A65
322.00
A89
446.00
A128
692.00
A18
145.00
A42
241.00
A66
323.00
A19
145.00
A90
451.00
A130
710.00
A43
244.00
A67
324.00
A91
472.00
A136
757.00
A20
145.00
A44
249.00
A68
325.00
A92
475.00
A140
757.00
A21
145.00
A45
251.00
A69
327.00
A22
163.00
A93
478.00
A144
764.00
A46
253.00
A70
335.00
A23
163.00
A94
487.00
A148
772.00
A47
257.00
A71
339.00
A24
163.00
A95
495.00
A150
774.00
A48
262.00
A72
343.00
A25
165.00
A96
511.00
A152
775.00
A49
264.00
A73
347.00
A26
171.00
A97
512.00
A154
786.00
A50
268.00 
A74
353.00
A27
173.00
A98
513.00
A156
821.00
A51
269.00 
A75
356.00
A28
177.00
A99
518.00
A158
823.00
A52
270.00
A76
357.00
A29
183.00 
A53
273.00
A100
525.00
A160
832.00
A77
360.00
A102
530.00
A162
847.00
A30
186.00
A54
276.00 
A78
364.00
A104
545.00
A165
850.00
A31
192.00
A55
$280.00
A79
366.00
A105
551.00
A168
853.00
A32
194.00
A56
282.00 
A80
372.00
A106
561.00
A170
860.00
A33
197.00
A57
285.00
A81
378.00
A34
199.00
A108
578.00
A173
866.00
A58
292.00
A82
381.00
A35
206.00
A110
591.00
A175
872.00
A59
295.00
A83
382.00
A112
604.00
A180
886.00
A36
211.00
A60
305.00
A84
384.00
A115
622.00
A185
912.00
A37
212.00 
A38
213.00 
A61 
310.00 
A62
315.00 
A86
419.00
A85
389.00
A116
629.00
A195
$962.00
A118
642.00
'''

table = table1.split("\n")
final = []
print(table)

cols, vals = [], []

for point in table:
    if len(point)>0:
        formatted = point.strip().split(" ")
        for data in formatted:
            if "A" in data:
                cols.append(data)
            else:
                vals.append(data)
print("Formatted")
map = {}
for index, val in enumerate(cols):
    print(cols[index], "|", vals[index], end=" | ")
    map[int(cols[index].replace("A", ""))] = vals[index]
    if (index+1)%5==0:
        print()
print()
new = sorted(map.items(), key= lambda item:item[0])
print(new)

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

calc(137)
i=0
rows = [['Size', 'Rate', 'Price']]
for key, value in new:
    rows.append([f'A{key}', value.replace("$", ""), calc(float(value.replace("$", "")))])
    # print(f'A{key}', value.replace("$", ""), calc(float(value.replace("$", ""))))
    # i += 1
    # if i==5:
    #     break

import pandas as pd
df = pd.DataFrame(rows)
df.to_csv("ACol.csv", index=False, header=False)