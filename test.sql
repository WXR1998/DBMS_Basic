drop database db;
create database db;
use db;
create table tutu (a1 int, a2 int, a3 int);
create table yeye (a1 int, a2 int);
alter table tutu add primary key (a1);
alter table yeye add constraint fk1 foreign key (a2) references tutu (a1);
insert into tutu (a1, a2) values (1,1),(2,2),(3,3),(4,4),(5,0),(6,1),(7,2);
insert into yeye (a2) values (1),(2),(4),(3);