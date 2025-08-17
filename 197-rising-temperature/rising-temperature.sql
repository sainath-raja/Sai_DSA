with cte as(
    select a.id, a.temperature as t1, b.temperature as t2,
    lead(a.recordDate) over(order by a.recordDate) as ld from Weather as a
    inner join Weather as b 
    on a.recordDate = dateadd(day, 1,  b.recordDate)
)
select id from cte
where t1 > t2