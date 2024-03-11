# Sorting
## Note: when running code files u should compile both the algo code file n utils.c as i didnt wanted to write printarray again n again i kept it in 1 file
```eg: gcc -o selection selecction_sort.c utils.c``` 

so why sorting? 

note: ah this iant gng deep coz i dont feel like n i m in shitty mood. maybe i will redo this when i get good mood n time , deeply

## bubble sort

compare adjacent elements and swap them..

Bubble sort consists of n rounds. On each round, the algorithm iterates through the elements of the array. Whenever two consecutive elements are found
that are not in correct order, the algorithm swaps them.

hm time complexity of bubble sort - o(n^2) - we can just look at number of for loops n say thts o(n^2)

implementation in `bubble_sort.c`

```

ok ERROR fck in c when i do sizeof(arr) i m getting bit weird 

i m lazy to explain it n not in mood

read https://stackoverflow.com/questions/33523585/how-do-sizeofarr-sizeofarr0-work

```

## selection sort

hm ok so to do this bit better , we can think of sorting as finidd smallest one n placing it at first right?

so well we do same here

first big ass unsorted array
find smallest
push it into frontmost..(consider this sorted and frm nw on push smallest frm unsorted to sorted parts end..ok)
and repeat this process

lets take an example [2.3.5.69.12.1,23] 
ok first this is all unsorted n ugly.. yucckkkkk
find smallest in this whole ass array -> 1
push it to fking end babyyy u belong there 
nw in remaining bunch of misfits aka [2,3,5,69,12,23] -> unsorted and [1] -> sorted
fuck repeat it keep repeatin git babbbyyy 

well... this also takes o(n^2) like bubble sort.. but then ytf we have this? well coz swaps suck n bubble sort does lot of swapss..


okay.. but is it really u kn really takin less swaps? yeah i kn u wud ask this

```
Algorithms/sorting/code on git main [x!?] via C v11.4.0-gcc 
> ./selection
swapswapswapswapswapswap11 12 22 25 34 64 90 


Algorithms/sorting/code on git main [x!?] via C v11.4.0-gcc 
> ./bubble   
swapswapswapswapswapswapswapswapswapswapswapswapswapswap11 12 22 25 34 64 90 

```

little bit u kn just a little bit but still sucks...

## merge sort

ah this needs recursion hmm

ahh whatever u kn hw selection sort worked ryt? we basically assumed our array as sorted n unsorted 

well... wut happens if we do it with half half n keep dng it forever ?
yeah merge sort

ok but is this better? idk i m dumb piece of shit so convince me tht this is better

ok ah well so..

um so lets say an arr of n elements

we nrmly broke this to n/2 and then this goes into n/4 and ...so on say n/2^k

so now well we need to find hw many times this k will be ryt? hw many times this got divided

n/2^k = 1

n=2^k

so log n boom k =log(n) base 2.

so this takes log(n)

and now when we merge back everytime we merge idk n elements ryt so its o(n) for eaach level  n there is log n 

so combined o(nlogn)




