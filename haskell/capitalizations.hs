-- Returns all possible capitalizations of a String

import           Data.Char     (toUpper, toLower)
import           Data.Foldable (traverse_)

slice :: Int -> Int -> [a] -> [a]
slice from to xs = take (to - from + 1) (drop from xs)

caps' :: String -> Int -> [String]
caps' [] _ = []
caps' xs i
    | i < length xs = [newUpper] ++ [newLower] ++ caps' newUpper (i + 1) ++ caps' newLower (i + 1)
    | otherwise = []
  where upper = toUpper $ xs !! i
        lower = toLower $ xs !! i
        prefix = slice 0 (i - 1) xs
        rest = slice (i + 1) (length xs) xs
        newUpper = prefix ++ [upper] ++ rest
        newLower = prefix ++ [lower] ++ rest

caps :: String ->[String]
caps x = caps' x 0

printWord :: String -> IO ()
printWord s = putStr $ "[" ++ s ++ "], "

main :: IO ()
main = traverse_ printWord (caps "aBc")
