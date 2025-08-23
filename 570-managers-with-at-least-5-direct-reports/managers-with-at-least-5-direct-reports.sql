with cte as(
    select managerId, count(managerId) as cnt from Employee 
    group by managerId
    having count(managerId) >= 5
)
select b.name from cte as a
inner join Employee as b
on b.id = a.managerId