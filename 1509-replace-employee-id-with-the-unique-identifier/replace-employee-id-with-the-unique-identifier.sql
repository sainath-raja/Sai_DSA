/* Write your T-SQL query statement below */
select unique_id, name from Employees as a
left join EmployeeUNI as b
on a.id = b.id