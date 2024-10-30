-- 코드를 입력하세요
SELECT MCDP_CD as '진료과 코드' , count(*) as '5월예약건수'
from APPOINTMENT
where date_format(APNT_YMD, "%Y-%m") like '2022-05'
group by MCDP_CD
order by count(*), MCDP_CD