/* Write your T-SQL query statement below */
with cte as(
    select a.customer_id, b.transaction_id from Visits as a
    left join Transactions as b
    on a.visit_id = b.visit_id
)
select customer_id, count(*) as count_no_trans  from cte
where transaction_id is null
group by customer_id