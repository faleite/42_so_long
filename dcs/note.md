# Notas

## Checagem do Mapa
1. Mapa deve ser do tipo .ber, se não, exibir mensagem de erro
2. So pode haver um mapa (argc == 2), se não, exibir mensagem de erro
3. Mapa deve conter apenas:
  - **E** 1 Saida
  - **C** Pelo menos 1 Coletavel
  - **P** 1 Posicao inicial

*Se o mapa contiver caracteres duplicados (saída/início), você deverá\
exibir uma mensagem de erro.*

4. Mapa deve ser retangular (quadrado ou retângulo), se não, exibir mensagem de erro
5. Mapa deve ser fechado/cercado por paredes, se não, exibir mensagem de erro
6. Mapa ter um caminho válido, se não, exibir mensagem de erro **(flood fill)**
7. Ser capaz de analisar qualquer tipo de mapa, desde que respeite as regras acima

*Se qualquer configuração incorreta de qualquer tipo for encontrada no arquivo,\
o programa deve sair de forma limpa e retornar "Error\n" seguido de uma mensagem\
de erro a sua escolha.*


## Function Hook
```c
	// Escuta as teclas (keypress)
	mlx_hook(data.win_ptr, 2, 1L, on_keypress, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, on_keypress, &data);
	// Escuta as teclas (keyrelease)
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, on_keypress, &data);

	// Escuta o movimento do mouse para fechar janela no click do botão x
	mlx_hook(data.win_ptr, 17, 0L, (int (*)(void *param))destroy_window, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, (int (*)(void *param))destroy_window, &data);
```
