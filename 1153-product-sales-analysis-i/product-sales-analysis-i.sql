/* Write your T-SQL query statement below */
select b.product_name, a.year, a.price from Sales as a
inner join Product as b
on a.product_id = b.product_id
