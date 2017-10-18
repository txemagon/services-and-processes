set nu
set cindent
set sw=4
set expandtab
set softtabstop=2
syntax on

source ~/.vim/vundle.vim

set t_Co=256
set syntax=on
" set background=dark
colorscheme distinguished

imap <C-c> <CR><Esc>O
set laststatus=2
let g:airline#extensions#tabline#enabled = 1

let g:ycm_path_to_python_interpreter = '/usr/bin/python'
let g:ycm_global_ycm_extra_conf = '~/.vim/ycm_extra_conf.py'

set backspace=2
let delimitMate_expand_cr = 1
let delimitMate_expand_space = 1

