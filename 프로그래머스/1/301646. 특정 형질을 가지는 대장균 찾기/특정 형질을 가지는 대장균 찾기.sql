select count(*) as COUNT from ECOLI_DATA
where GENOTYPE & 2 = 0 AND GENOTYPE & 5 != 0