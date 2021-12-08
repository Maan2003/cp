for us to statisfy the contraints
- first element of list must be same as last
- all first elements of remaining lists must be same

`n` = size of array
`x` = frequency of the most frequent element `E`

we need to remove atleast n - x lists, 
i.e all lists not starting with `E`
`n - x` operations

lets assume all these lists gets merged into the first instance of `E` (`E1`)
so now to make the start element of list `E1` same as `E` 
we need to take another instance of `E` and merge it so `1` more operation

but this operation might not be needed if `n - x` is 0, i.e. all elements are same
