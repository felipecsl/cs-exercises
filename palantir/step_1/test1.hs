import Data.HashMap.Strict
firstNonRepeatingChar a = toList $ fromListWith (+) [(c, 1) | c <- a]