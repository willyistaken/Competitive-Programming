# .vimrc
```
:set ai
:set bg=dark
:set tabstop=4
:set shiftwidth=4
:set mouse=a
:set history=100
syntax on
:set t_Co=256
:set nu
:set relativenumber
:set guicursor=
colorscheme nord

:inoremap ( ()<Esc>i
:inoremap ' ''<Esc>i
:inoremap " ""<Esc>i
:inoremap [ []<Esc>i
:inoremap {<CR> {<CR>}<Esc>i
:inoremap jj <Esc>
map <F5> :w<CR>:<C-U>!g++ -DLOCAL -Wall -g  -Wextra -Wno-unused-result -static %:r.cpp -o %:r &&echo "Compiled" && ./%:r<CR>
map m $
map n ^
imap <F5> <Esc><F5>
imap <F12> #include<bits/stdc++.h><CR>using namespace std;<CR>typedef long long ll;<CR>//#include<bits/extc++.h><CR>//__gnu_pbds::<CR><CR><CR><CR><CR>int main(<Esc>la{<CR>	ios_base::sync_with_stdio(0jjla,cin.tie(0jjla,cout.tie(0jjla;<CR><CR><CR>return 0;<CR><Bs>

```
# 其他


