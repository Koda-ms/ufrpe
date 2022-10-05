package main

import(
	"fmt"
  "sync"
	"time"
  "strconv"
)

type Buffer struct{
	buffer string
	tamanho int
	CAPACIDADE int
}

var mutex sync.Mutex

func ThreadInsere(b *Buffer,  s string)  {
  for i := 0; i < 500; i++ {
    inserir(b, s)
    time.Sleep(100 * time.Millisecond)
  }
}

func inserir(b *Buffer, s string){
  mutex.Lock()
  if b.tamanho < b.CAPACIDADE{
    b.buffer = b.buffer + s
    b.tamanho++
    mutex.Unlock()
  } else {
    mutex.Unlock()
    time.Sleep(100 * time.Millisecond)
  }
}

func esvaziar(b *Buffer) string{
  for b.tamanho < b.CAPACIDADE{
    time.Sleep(100 * time.Millisecond)
  }
  mutex.Lock()
  b.tamanho = 0
  final := b.buffer
  b.buffer = ""
  
  mutex.Unlock()
  return final
}

func main()  {
  var buf = Buffer{"", 0, 100}
  
	for i := 0; i < 3; i++ {
    go ThreadInsere(&buf, strconv.Itoa(i+1))
		go ThreadInsere(&buf, strconv.Itoa(i+1))
    go ThreadInsere(&buf, strconv.Itoa(i+1))
	}
  
  for j := 0; j < 10; j++ {
    Print := esvaziar(&buf)

    fmt.Printf("Print %d: %s\n\n", (j+1), Print)
  }
}