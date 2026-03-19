# Interpretador por Linha de Comando

Shell simplificado implementado em C para a cadeira de Infraestrutura de Software.

- Sistema operational: **Linux**

## Arquivos

- main.c — loop principal, modo interativo e batch, despacho de comandos
- line.c — leitura de input e parsing da linha em argumentos
- execute.c — execução de comandos externos via fork/execvp, gerenciamento de background
- builtins.c — implementação dos comandos built-in: cd e fg

## Compilar

```bash
make
```

## Executar

Modo interativo:
```bash
./shell
```

Modo batchfile:
```bash
./shell arquivo.txt
```