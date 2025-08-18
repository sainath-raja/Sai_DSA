    select a.name,b.bonus from Employee as a
    left join Bonus as b
    on a.empId = b.empId
    where b.bonus < 1000 or b.bonus is null
