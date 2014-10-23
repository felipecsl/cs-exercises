# Write a method that returns whether the set of cards provided in an integer array is a
# poker straight or not.
# http://en.wikipedia.org/wiki/List_of_poker_hands#Straight

straight :: (Num a, Ord a) => [a] -> Bool
straight [] = False
straight [x] = True
straight [13,1] = True
straight (x:xs) = head(xs) - x == 1 && straight(xs)

main = do
  putStrLn("Test cases:")
  putStrLn("")
  putStrLn("straight [1, 2] -> " ++ show(straight([1, 2])))
  putStrLn("straight [2, 3, 4] -> " ++ show(straight([2, 3, 4])))
  putStrLn("straight [1, 2, 3] -> " ++ show(straight([1, 2, 3])))
  putStrLn("straight [12, 13, 1] -> " ++ show(straight([12, 13, 1])))
  putStrLn("straight [2] -> " ++ show(straight([2])))
  putStrLn("----")
  putStrLn("straight [2, 3, 5] -> " ++ show(straight([2, 3, 5])))
  putStrLn("straight [3, 2, 1] -> " ++ show(straight([3, 2, 1])))
  putStrLn("straight [9, 10, 1] -> " ++ show(straight([9, 10, 1])))
  putStrLn("straight [1, 7, 1] -> " ++ show(straight([1, 7, 1])))
  putStrLn("straight [] -> " ++ show(straight([])))
