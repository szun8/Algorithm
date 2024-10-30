-- 코드를 입력하세요
SELECT MONTH(START_DATE) as MONTH, CAR_ID, count(*) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
where CAR_ID in(
        select CAR_ID from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
        where date_format(START_DATE, "%Y-%m") between '2022-08' and '2022-10'
        group by CAR_ID
        having count(CAR_ID) >= 5) and start_date BETWEEN '2022-08-01' AND '2022-10-31'
GROUP  BY month, car_id
order by MONTH, CAR_ID desc