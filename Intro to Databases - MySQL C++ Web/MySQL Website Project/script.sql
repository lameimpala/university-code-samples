create table s(snum int auto_increment primary key, sname varchar(255), status int, city varchar(255));
insert into s(sname,status,city)  values ('Smith',20,'London');
insert into s(sname,status,city)  values ('Jones',10,'Paris');
 insert into s(sname,status,city)  values ('Blake',30,'Paris');
insert into s(sname,status,city)  values ('Clark',20,'London');
 insert into s(sname,status,city)  values ('Adams',30,'Athens');


create table p(pnum int auto_increment primary key, pname varchar(255), color varchar(255), weight int);
 insert into p(pname,color,weight) values ('Nut','Red','12');  
insert into p(pname,color,weight)  values ('Bolt','Green','17');
insert into p(pname,color,weight)  values ('Screw','Blue','17');
 insert into p(pname,color,weight)  values ('Screw','Red','14');
 insert into p(pname,color,weight) values ('Cam','Blue','12');
insert into p(pname,color,weight) values ('Cog','Red','19');

 create table sp(snum int, pnum int, qty int(7), primary key (snum,pnum), foreign key (snum) references s(snum), foreign key (pnum) references p(pnum));
