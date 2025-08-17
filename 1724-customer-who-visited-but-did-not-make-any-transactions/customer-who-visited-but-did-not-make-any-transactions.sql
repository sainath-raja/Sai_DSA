/* Write your T-SQL query statement below */
    select count(*) as count_no_trans, a.customer_id from Visits as a
    left join Transactions as b
    on a.visit_id = b.visit_id
    where b.visit_id is null
    group by customer_id
