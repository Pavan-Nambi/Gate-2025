So what is it? What is a data structure?

Its all about a place where we can store data or retrieve it. 

Why is it so goddamn important? Well, companies got huge ass data, right? And this data keeps on growing so it sucks and we need to be able to store and retrieve it efficiently to save money.  

Okay, so:

## Array

In computer science, an array is a data structure consisting of a collection of elements (values or variables), of same memory size, each identified by at least one array index.

```C
#include <stdio.h> 
#include <stdint.h>

void main(void){

int arr[4] = {4,1,4};

}

```

hmm.. ok but.. wtf is this `arr[4]` dng ? allocating memory continously? is it rly dng it? REALLY? hw does it do it? heck i want to kn wtf this stupid ass `main()` does underhood but thts for anthr time.

Run this file using `gdb`. or just get the `assembly` file for our c file.

for gdb click below details well its hard to explain using gdb so i didnt rly explained it tht well.

<details>
## using gdb

if u decide to use `gdb` , figure out installation ur own.

eg: if your c file name is hello.c and if u ran ` gcc -g -o hello hello.c`your executable is `hello`

note: -g --> is used to get debug information , -o -s to specify to output it to hello not some stupid a.exe 

commands to run

```zsh
gdb your_executable 

// after gdb starts 

start // this starts up debugger for u with lots of clutter , u can look at ur screena dn figure out abt it
```

for example this is what happens when i do start aftr running `gdb hello` and `start`

```as

─── Output/messages ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Temporary breakpoint 1, main () at hello.c:4
4	void main(void){
─── Assembly ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
~
 0x0000555555555149  main+0  endbr64
 0x000055555555514d  main+4  push   %rbp
 0x000055555555514e  main+5  mov    %rsp,%rbp
 0x0000555555555151  main+8  sub    $0x20,%rsp
!0x0000555555555155  main+12 mov    %fs:0x28,%rax
 0x000055555555515e  main+21 mov    %rax,-0x8(%rbp)
 0x0000555555555162  main+25 xor    %eax,%eax
 0x0000555555555164  main+27 movq   $0x0,-0x20(%rbp)
 0x000055555555516c  main+35 movq   $0x0,-0x18(%rbp)
─── Breakpoints ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
[1] break once at 0x0000555555555155 in hello.c:4 for -qualified main hit 1 time
─── Expressions ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
─── History ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
─── Memory ───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
─── Registers ────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
    rax 0x0000555555555149     rbx 0x0000000000000000       rcx 0x0000555555557dc0    rdx 0x00007fffffffbb78    rsi 0x00007fffffffbb68
    rdi 0x0000000000000001     rbp 0x00007fffffffba50       rsp 0x00007fffffffba30     r8 0x00007ffff7e1bf10     r9 0x00007ffff7fc9040
    r10 0x00007ffff7fc3908     r11 0x00007ffff7fde660       r12 0x00007fffffffbb68    r13 0x0000555555555149    r14 0x0000555555557dc0
    r15 0x00007ffff7ffd040     rip 0x0000555555555155    eflags [ PF IF ]              cs 0x00000033             ss 0x0000002b
     ds 0x00000000              es 0x00000000                fs 0x00000000             gs 0x00000000             k0 0x0000000000100001
     k1 0x0000000000000000      k2 0x0000000000000000        k3 0x0000000000000000     k4 0x0000000000000000     k5 0x0000000000000000
     k6 0x0000000000000000      k7 0x0000000000000000
─── Source ───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
~
~
 1  #include <stdio.h>
 2  #include <stdint.h>
 3
!4  void main(void){
 5
 6  int arr[4] = {4,1,4};
 7
 8  }
─── Stack ────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
[0] from 0x0000555555555155 in main+12 at hello.c:4
─── Threads ──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
[1] id 41278 name hello from 0x0000555555555155 in main+12 at hello.c:4
─── Variables ────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
loc arr = {[0] = 0, [1] = 0, [2] = 0, [3] = 0}
──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
>>>

```

um yeah.. ikr lots of shit lots of shit , lets forget abt all of this shit n run it type `n` (means run next line u can type `next` too but its.. long)  ok so like that u can run net line next line.. and see which assembly code is running for what part of your src code... ok  to exit type `exit`

this is annying to use to explain things so fck i am going to generate assembly 

if u r ok with above gdb thing by all means u can do it and see for line by line but for me its kinda hard to copy paste this for every `next` i will run so well assemblyyyyyyy
</details>

## to generate assembly

```bash
 gcc -S -o hello.s hello.c
```
so our code is  essentially just array

```c
int arr[4] = {4,1,4};
```

an array by definition is - data structure consisting of a collection of elements (values or variables), of same memory size, each identified by at least one array index.

"same memory size" for all values.

here we are saying its int - 4 bytes (note this might be diff depending on platform windows mac n even prog languages) - this is for c on linux


so for our array we need total 4*4 = 16 bytes. 


now open [hello.s](https://github.com/Pavan-Nambi/Gate-2025/blob/main/CS/DSA/hello.s)) file.


ignore everything and lets just look at our array assignment stuff

```wasm
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movl	$4, -32(%rbp)
	movl	$1, -28(%rbp)
	movl	$4, -24(%rbp)
```

kinda weird right y tht many `mov` statements?
```
note: 
rbp and rsp are special purpose registers
rbp - kinda like base pointer on where we r in our current context/stack frame
rsp -> points to top pointer for current stack frame
```

first movq - mov quadriple something  - 64 bit

movl - mov long 32 bit

hmm interesting y it has 2 movq statements and then 3 movl???
coz my machine is x86_64 archictecture.. so 64 bits default dummass but then compier realises it dont need 64 bits aka 8 bytes n becomes 4 bytes so movl aka 32 bits

1 byte = 8 bits
so 4 bytes  = 32 bits , 8 bytes = 64 bits

first compiler just dng it like 32-24 -> 8 bytes and 24-16 -> 8 bytes 
total bytes 16 ok
so first we r moving 0's to all those spaces. default mechanism in c.

now as our integers r just 32 bits.. its using movl which resulting in it only taking 4 bytes space ( see -32-28-24) difference ->4

4 is stored in 32(%rbp)-28(%rbp)

1 is in 28 - 24

4 in 24 -20 


and 24-16 is alrdy 0 as we first made it 0... makes sense?

okay fuck so now we kn this is ACTUALLY FUCKING CONTIGUOUS IN MEMORY TOO right? not just listening to someone but we actually saw its contigous/continous whatever shit it is.


and if u look at [hello.s](https://github.com/Pavan-Nambi/Gate-2025/blob/main/CS/DSA/hello.s) file again
we see something like `pushq`????? 
so we r pushing it to a goddamn stack??? 
if size n all is knwn its pushed to a call stack else to a memory heap ok

insertin n all ahh blah blah not interesting it just takes 1 step `movl $value -addr(rbp)`

hm but to insert in middle without deleting anything takes more time.... n space so linkedlist ig idk exactly but nw we gng to stacks as ntg else is interesting in arr


## Stack

well.. stack is basically a weird type of array.

where ntg else matters indexing my ass u gimme something i keep it there in order.

lifo

but y stack??  y making array dumber??

in a scenario where order matters , using arrys wud suck...

undo we do in our ide , if its with stack it sounds doable as its just lifo, with array...? umm sounds too hard ryt coz we need to resize arr everytime... n then deletin n all..

lets just think abt our earlier code whole thing is in stack..? but y? coz we need out code to be ran in a sequential order.. 

moral: its better to be dumass sometimes..

for stack implementation see [stack.c](https://github.com/Pavan-Nambi/Gate-2025/blob/main/CS/DSA/stack.c)


ain't writting abt assembly here coz its long n i m lazy n by nw u shud get basic idea n u can look into it urself.