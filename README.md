# SpaceInvaders_in_C
Este repositório contém a implementação de uma versão simplificada do jogo Arcade Space Invaders, desenvolvida inteiramente em linguagem C para execução em terminal. O projeto é o trabalho prático da disciplina de Programação I (INF15927).

## 🚀 Dinâmica do Jogo

O jogador controla uma nave que se move horizontalmente na base de um mapa 21x11, com o objetivo de eliminar duas fileiras de naves alienígenas antes que elas atinjam a base ou que as vidas do jogador se esgotem.

**Características Técnicas:**
* Atualização do estado do mapa a cada iteração (movimentos, colisões e tiros).
* Geração de mapas de calor para rastrear a trajetória dos tiros.
* Leitura de estados iniciais e personagens via manipulação de arquivos `.txt`.
* Restrição estrita ao uso de caracteres da tabela ASCII e proibição de alocação dinâmica (ponteiros).

## ⚙️ Pré-requisitos

* Compilador `gcc`.
* Terminal compatível (Linux/Unix recomendado).
* Ferramentas de comparação de texto como `diff` ou `meld` para validação das saídas.

## 📦 Compilação e Execução

Todo o código está centralizado em um único arquivo `.c` dentro do diretório `src/`.

1. **Compilar o código:**
   ```bash
   gcc src/isabella_mendes.c -o src/space_invaders -Wall
