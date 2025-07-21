select a.id from Weather as a
inner join Weather as b
on a.recordDate = dateadd(day, 1, b.recordDate)
where a.temperature > b.temperature
