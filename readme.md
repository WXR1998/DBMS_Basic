# 系统表
- RelCat:
    table名, table一条记录的长度, table的attr数量, table有多少个索引, table是否有主键
- AttrCat:
    table名, attr名, attr在记录中的偏移, attr类型, attr长度, attr索引编号, 在主键中的排序编号, 是否非空, attr是否存在默认值, 默认值
- FkCat:
    fk名, 从table, 主table, attr数, 从attr1, 从attr2，从attr3, 主attr1, 主attr2, 主attr3
- IdxCat:
    idxName, table名, attr名

完成：  
    插入有默认值的键时，在建表的时候可以将该属性放进系统表
    保存attr默认值的时候有一个Magic Number，如果是这个数则表示是NULL

# 默认值
每个attr可能有默认值，为了实现的方便，默认值设定最长为20字节                [这里相对于原来的要求做了改动]
如果attr有默认值，插入一条新行的时候检查该列是否有值，如果没有则将默认值插入进去
加入了一条新语法：  INSERT INTO tbName ( colList ) VALUES ( valueList );
完成：
    现在默认值可以自动加入了

# 添加主键
主键的性质：不能重复，每张表只有一个主键，主键对应的行元素不可重复
主键可以由多个attr组成，所以需要在AttrCat中增加一列，表示当前表的主键含有哪些attr
主键如何维护？
    如果当前表有主键，则插入的时候需要检查是否存在同主键元素的行，修改的时候需要检查是否存在同主键元素的行
    修改的时候，方便起见不考虑复合主键的情况，只考虑单列主键情况下是否会出现不符合完整性的情况。    [这里相对于原来的要求做了改动]
    并且逐setClause句地执行

完成：
    主键的完整性维护完成

# 添加外键约束
从表的外键指向的是主表的主键，但一张表可以存在多个外键，所以需要一个表来存放
外键是依附在一组attr上的属性。所以我们可以使用单独的一张表来存放所有的外键。
为了实现的方便，外键最多有3个attr。         [这里相对于原来的要求做了改动]

# 外键完整性约束
- 给定的键应该是主表的主键。
- 插入和修改的时候要注意维护完整性。
对于从表的插入和修改，应先去主表查找是否存在对应的键值；对于主表的删除，应先去从表查找是否被引用。

# 添加索引
为了实现的方便，索引都是单列的。    [这里相对于原来的要求做了改动]
索引的功能是这样的：针对某列元素排序后建立B+树，然后查询的时候可以在B+树上直接操作，效率更高
完成： 
    现在可以实现索引的添加和删除

# 更改表的信息
增加一列：  删除所有表的信息，然后新建一个表，其增加了一列
删除一列：  同上
修改一列：  同上
重命名一列：    同上


加主键：    检查完整性(是否有相同元素)，修改在meta中的信息           完成
删主键：    检查完整性(是否是其他表的外键)，修改在meta中的信息       完成
加外键：    检查完整性(是否是主表的主键)，修改在meta中的信息
删外键：    修改在meta中的信息

# bug