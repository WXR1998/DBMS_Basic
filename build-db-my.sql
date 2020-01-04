drop database evaldb;
create database evaldb;
use evaldb;
create table part (
    p_partkey		int,
    p_name			varchar(55),
    p_mfgr			varchar(25),
    p_brand			varchar(10),
    p_type			varchar(25),
    p_size			int,
    p_container		varchar(10),
    p_retailprice	float,
    p_comment		varchar(23),
    primary key (p_partkey)
);
create table region (
    r_regionkey	    int,
    r_name		    varchar(25),
    r_comment	    varchar(152),
    primary key (r_regionkey)
);
create table nation (
    n_nationkey		int,
    n_name			varchar(25),
    n_regionkey		int not null,
    n_comment		varchar(152),
    primary key (n_nationkey)
);
create table supplier (
    s_suppkey		int,
    s_name			varchar(25),
    s_address		varchar(40),
    s_nationkey		int not null,
    s_phone			varchar(15),
    s_acctbal		float,
    s_comment		varchar(101),
    primary key (s_suppkey)
);
create table customer (
    c_custkey		int,
    c_name			varchar(25),
    c_address		varchar(40),
    c_nationkey		int not null,
    c_phone			varchar(15),
    c_acctbal		float,
    c_mktsegment	varchar(10),
    c_comment		varchar(117),
    primary key (c_custkey)
);
create table partsupp (
    ps_partkey		int not null,
    ps_availqty		int,
    ps_suppkey		int not null,
    ps_supplycost	float,
    ps_comment		varchar(199),
    primary key (ps_partkey, ps_suppkey)
);
create table orders (
    o_orderkey		int,
    o_custkey		int not null,
    o_orderstatus	varchar(1),
    o_totalprice	float,
    o_orderdate		date,
    o_orderpriority	varchar(15),
    o_clerk			varchar(15),
    o_shippriority	int,
    o_comment		varchar(79),
    primary key (o_orderkey)
);
create table lineitem (
    l_orderkey		int not null,
    l_partkey		int not null,
    l_suppkey		int not null,
    l_linenumber	int,
    l_quantity		float,
    l_extendedprice	float,
    l_discount		float,
    l_tax			float,
    l_returnflag	varchar(1),
    l_linestatus	varchar(1),
    l_shipdate		date,
    l_commitdate	date,
    l_receiptdate	date,
    l_shipinstruct	varchar(25),
    l_shipmode		varchar(10),
    l_comment		varchar(44),
    primary key (l_orderkey, l_linenumber)  
);
alter table supplier add constraint fk1 foreign key (s_nationkey) references nation(n_nationkey);

alter table partsupp add constraint fk2 foreign key (ps_partkey) references part(p_partkey);
alter table partsupp add constraint fk3 foreign key (ps_suppkey) references supplier(s_suppkey);

alter table customer add constraint fk4 foreign key (c_nationkey) references nation(n_nationkey);

alter table orders add constraint fk5 foreign key (o_custkey) references customer(c_custkey);

alter table lineitem add constraint fk6 foreign key (l_orderkey) references orders(o_orderkey);
alter table lineitem add constraint fk7 foreign key (l_partkey,l_suppkey) references partsupp(ps_partkey,ps_suppkey);

alter table nation add constraint fk8 foreign key (n_regionkey) references region(r_regionkey);
