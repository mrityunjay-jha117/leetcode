# Write your MySQL query statement below
select id,
case
when id%2=1 and id<(select max(id) from seat)
then lead(student,1) over (order by id)
when id%2=0
then lag(student,1) over (order by id)
else  student
end
as student
from seat

