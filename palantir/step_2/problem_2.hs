-- maxSublist :: (Num a, Ord a) => [a] -> a
-- maxSublist [] = 0
-- maxSublist (x:xs) = max x (x + maxSublist xs)

max_sublist l = ureverse $ fst $ foldl find_max ([],(0,[],0)) l where
  find_max (max, (sum, r, rsum)) x = (max', (sum', r', rsum'))
    where
    (r', rsum')  = if (rsum > 0)
                   then (x:r, rsum+x)
                   else ([x], x)
    (max', sum') = if (rsum' > sum)
                   then (r', rsum')
                   else (max, sum)
