import os

# 0表示是int或者float，1是str，2是date
tableAttrType = {
    'part':     [0, 1, 1, 1, 1, 0, 1, 0, 1],
    'region':   [0, 1, 1],
    'nation':   [0, 1, 0, 1],
    'supplier': [0, 1, 1, 0, 1, 0, 1],
    'customer': [0, 1, 1, 0, 1, 0, 1, 1],
    'partsupp': [0, 0, 0, 0, 1],
    'orders':   [0, 0, 1, 0, 2, 1, 1, 0, 1],
    'lineitem': [0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 1, 1, 1]
}

initial = 'use evaldb;\n'
ending = 'use evaldb;\n'

for root, dirs, files in os.walk('.'):
    for f in files:
        if f[-3:] == 'tbl':
            tableName = f[:-4]
            with open(os.path.join(root, f), 'r') as fin:
                with open(os.path.join(root, '%s.sql'%tableName), 'w') as fout:
                    fout.write(initial)
                    for line in fin:
                        items = line.split('|')[:-1]
                        assert(len(items) == len(tableAttrType[tableName]))
                        values = ''
                        for i in range(len(items)):
                            item = items[i]
                            if tableAttrType[tableName][i] == 1:
                                item = '\'' + item + '\''
                            elif tableAttrType[tableName][i] == 2:
                                item = '|' + item + '|'
                            values = values + item + (', ' if i != len(items) -1 else '')
                        sqlstr = 'INSERT INTO %s VALUES (%s)%s;\n' % (tableName, values, ' FORCE' if tableName == 'lineitem' else '')
                        fout.write(sqlstr)
                    fout.write(ending)