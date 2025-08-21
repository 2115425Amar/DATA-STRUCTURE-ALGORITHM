SELECT customer_id, SUM(amount) AS total_spent
FROM sales
WHERE date >= CURRENT_DATE - INTERVAL '3 months'
GROUP BY customer_id
ORDER BY total_spent DESC
LIMIT 5;




select customer_id
from Customer
group by customer_id
having count(distinct product_key) = (
    select count(*) from product
)

--  second max element fron table
select max(amount) as second_max
from sales  
where amount < (select max(amount) from sales);

-- SELECT salary
-- FROM employees
-- ORDER BY salary DESC
-- LIMIT 1 OFFSET 1;