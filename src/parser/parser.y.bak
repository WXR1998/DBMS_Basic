sql:
    command
            {

            }
    | sql ';' command 
            {

            }
    ;

command:
            {

            }
    | SHOW DATABASES
            {
                // TODO
            }
    | SELECT STAR FROM relations whereclause
            {
                $$ = new SelectTree($4, $5);
                Tree::setInstance($$);
                Tree::run();
            }
    | SELECT attributes FROM relations whereclause
            {
                $$ = new SelectTree($2, $4, $5);
                Tree::setInstance($$);
                Tree::run();
            }
    | INSERT INTO IDENTIFIER VALUES insertData
            {
                $$ = new InsertTree($3, $5);
                Tree::setInstance($$);
                delete $3;
                Tree::run();
            }
    | UPDATE IDENTIFIER SET attribute EQ constvalue whereclause
            {
                // TODO
                $$ = new UpdateTree($2, $4, $6, $7);
                Tree::setInstance($$);
                delete $2;
                Tree::run();
            }
    | DELETE FROM IDENTIFIER whereclause
            {
                $$ = new DeleteTree($3, $4);
                Tree::setInstance($$);
                delete $3;
                Tree::run();
            }
    | CREATE DATABASE IDENTIFIER
            {
                $$ = new CreateDatabaseTree($3);
                Tree::setInstance($$);
                delete $3;
                Tree::run();
            }
    | CREATE TABLE IDENTIFIER '(' columns ')'
            {
                $$ = new CreateTableTree($3, $5);
                Tree::setInstance($$);
                delete $3;
                Tree::run();
            }
    | DROP DATABASE IDENTIFIER
            {
                $$ = new DropDatabaseTree($3);
                Tree::setInstance($$);
                delete $3;
                Tree::run();
            }
    | DROP TABLE IDENTIFIER
            {
                $$ = new DropTableTree($3);
                Tree::setInstance($$);
                delete $3;
                Tree::run();
            }
    | USE IDENTIFIER
            {
                $$ = new UseDatabaseTree($2);
                Tree::setInstance($$);
                delete $2;
                Tree::run();
            }
    | DESC IDENTIFIER
            {
                $$ = new DescTableTree($2);
                Tree::setInstance($$);
                delete $2;
                Tree::run();
            }
    | CREATE INDEX IDENTIFIER '(' attribute ')'
            {
                $$ = new CreateIndexTree($3, $5);
                Tree::setInstance($$);
                delete $3;
                Tree::run();
            }
    | DROP INDEX IDENTIFIER '(' attribute ')'
            {
                $$ = new DropIndexTree($3, $5);
                Tree::setInstance($$);
                delete $3;
                Tree::run();
            }
    | DESC
            {
                $$ = new DescTableTree("");
                Tree::setInstance($$);
                Tree::run();
            }
    | SHOW TABLES
            {
                $$ = new DescTableTree("");
                Tree::setInstance($$);
                Tree::run();
            }
    ;

insertData:
    '(' constvalues ')'
            {
                $$ = new InsertValueTree($2);
            }
    | insertData ',' '(' constvalues ')'
            {
                $$->addConstValues($4);
            }
    ;

columns:
    columnsTmp
            {

            }
    | columnsTmp ',' PRIMARY '(' IDENTIFIER ')'
            {
                bool found = $$->setPrimaryKey($5);
                if(!found) {yyerror("Primary Key Set Failed!");}
                delete $5;
            }
    
    | columnsTmp ',' FOREIGN '(' IDENTIFIER ')' REFERENCES IDENTIFIER '(' IDENTIFIER ')'
            {
                // TODO
            }
    ;

columnsTmp:
    column
            {
                $$ = new ColumnsTree();
                $$->addColumn($1);
            }
    | columnsTmp ',' column
            {
                $$->addColumn($3);
            }
    ;

type:
    KINT
            {
                $$ = new TypeTree(AttrType::T_INT);
            }
    | KINT '(' INTEGER ')'
            {
                $$ = new TypeTree(AttrType::T_INT, $3);
            }
    | KFLOAT
            {
                $$ = new TypeTree(AttrType::T_FLOAT);
            }
    | KVARCHAR '(' INTEGER ')'
            {
                $$ = new TypeTree(AttrType::T_STRING, $3);
            }
    | DATE
            {
                $$ = new TypeTree(AttrType::T_STRING, 10);
            }
    ;

column:
    IDENTIFIER type
            {
                $$ = new ColumnTree($1, $2->getType(), $2->getLen());
                delete $1;
                delete $2;
            }
    | IDENTIFIER type NOTNULL
            {
                $$ = new ColumnTree($1, $2->getType(), $2->getLen(), 1);
                delete $1;
                delete $2;
            }
    | IDENTIFIER type DEFAULT constvalue
            {
                $$ = new ColumnTree($1, $2->getType(), $2->getLen(), 0, $4);
                delete $1;
                delete $2;
            }
    | IDENTIFIER type NOTNULL DEFAULT constvalue
            {
                $$ = new ColumnTree($1, $2->getType(), $2->getLen(), 1, $5);
                delete $1;
                delete $2;
            }
    ;

    /*
column:
    columnInt
            {
                $$ = $1;
            }
    | columnInt NOTNULL
            {
                $1->setNotNull(1);
                $$ = $1;
            }
    | IDENTIFIER KFLOAT
            {
                $$ = new ColumnTree($1, AttrType::T_FLOAT);
                delete $1;
            }
    | IDENTIFIER KFLOAT NOTNULL
            {
                $$ = new ColumnTree($1, AttrType::T_FLOAT, 4, 0, 1);
                delete $1;
            }
    | IDENTIFIER KVARCHAR '(' INTEGER ')'
            {
                $$ = new ColumnTree($1, AttrType::T_STRING, $4);
                delete $1;
            }
    | IDENTIFIER KVARCHAR '(' INTEGER ')' NOTNULL
            {
                $$ = new ColumnTree($1, AttrType::T_STRING, $4, 0, 1);
                delete $1;
            }
    ;

columnInt:
    IDENTIFIER KINT
            {
                $$ = new ColumnTree($1, AttrType::T_INT);
                delete $1;
            }
    | IDENTIFIER KINT '(' INTEGER ')'
            {
                // TODO
                $$ = new ColumnTree($1, AttrType::T_INT);
                delete $1;
            }
    ;
    */

attributes:
    attrList
            {
                $$ = $1;
            }
    ;

attrList:
    attribute
            {
                $$ = new AttributesTree();
                $$->addAttribute($1);
            }
    | attrList ',' attribute
            {
                $$->addAttribute($3);
            }
    ;

attribute:
    IDENTIFIER
            {
                $$ = new AttributeTree($1);
                delete $1;
            }
    | IDENTIFIER '.' IDENTIFIER
            {
                $$ = new AttributeTree($1, $3);
                delete $1;
                delete $3;
            }
    ;

relations:
    IDENTIFIER
            {
                $$ = new RelationsTree();
                $$->addRelation($1);
                delete $1;
            }
    | relations ',' IDENTIFIER
            {
                $$->addRelation($3);
                delete $3;
            }
    ;

whereclause:
    WHERE conditions
            {
                $$ = new WhereClauseTree($2);
            }
    |
            {
                $$ = nullptr;
            }
    ;

conditions:
    comparison
            {
                $$ = new ConditionsTree();
                $$->addComparison($1);
            }
    | conditions AND comparison
            {
                $$->addComparison($3);
            }
    ;

comparison:
    attribute EQ constvalue
            {
                $$ = new ComparisonTree($1, CmpOP::T_EQ, $3);
            }
    | attribute GT constvalue
            {
                $$ = new ComparisonTree($1, CmpOP::T_GT, $3);
            }
    | attribute LT constvalue
            {
                $$ = new ComparisonTree($1, CmpOP::T_LT, $3);
            }
    | attribute GE constvalue
            {
                $$ = new ComparisonTree($1, CmpOP::T_GE, $3);
            }
    | attribute LE constvalue
            {
                $$ = new ComparisonTree($1, CmpOP::T_LE, $3);
            }
    | attribute NE constvalue
            {
                $$ = new ComparisonTree($1, CmpOP::T_NE, $3);
            }
    | attribute IS T_NULL
            {
                $$ = new ComparisonTree($1, CmpOP::T_ISNULL);
            }
    | attribute IS NOTNULL
            {
                $$ = new ComparisonTree($1, CmpOP::T_ISNOTNULL);
            }
    | attribute EQ attribute
            {
                $$ = new ComparisonTree($1, CmpOP::T_EQ, $3);
            }
    | attribute GT attribute
            {
                $$ = new ComparisonTree($1, CmpOP::T_GT, $3);
            }
    | attribute LT attribute
            {
                $$ = new ComparisonTree($1, CmpOP::T_LT, $3);
            }
    | attribute GE attribute
            {
                $$ = new ComparisonTree($1, CmpOP::T_GE, $3);
            }
    | attribute LE attribute
            {
                $$ = new ComparisonTree($1, CmpOP::T_LE, $3);
            }
    | attribute NE attribute
            {
                $$ = new ComparisonTree($1, CmpOP::T_NE, $3);
            }
    ;

constvalues:
    constvalue
            {
                $$ = new ConstValuesTree();
                $$->addConstValue($1);
            }
    | constvalues ',' constvalue
            {
                $$->addConstValue($3);
            }
    ;

constvalue:
    INTEGER         { $$ = new ConstValueTree($1); }
    | FLOAT         { $$ = new ConstValueTree($1); }
    | STRING        { $$ = new ConstValueTree($1); delete $1; }
    | T_NULL          { $$ = new ConstValueTree(0); $$->setNull(); }
    ;