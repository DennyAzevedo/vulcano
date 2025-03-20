# Automação da Inspeção de Segmentos de Matrizes de Cristal Líquido

## Visão Geral

Este projeto apresenta uma arquitetura de sistema para automatizar o processo de inspeção funcional de segmentos de matrizes de cristal líquido. O foco principal é a elaboração e validação do aplicativo de inspeção, que utiliza um algoritmo baseado em vizinhança e conectividade para avaliar a integridade dos segmentos. Os testes operacionais realizados demonstraram a eficácia do sistema e do algoritmo implementado.

## Tecnologias Utilizadas

- **Linguagem de Programação**: Borland C++ Builder 6.0
- **Bibliotecas**: JEDI (da comunidade SourceForge), Victor Image Processing Library
- **Banco de Dados**: Paradox
- **Hardware**:
  - Câmera CCD
  - Placa de digitalização PixelSmart512-8 (PS512-8)
  - Dispositivos diversos de captura, incluindo WebCam

## Funcionalidades Principais

- Captura e tratamento de imagens
- Algoritmo de vizinhança para identificação de elementos e pixels
- Cálculo do centróide dos elementos
- Determinação da base de referência
- Cálculo da métrica Euclidiana entre elementos e referência
- Cálculo da proporção entre métricas para comparação de imagens inspecionadas

## Versões do Sistema

1. **Simple Version**: 
   - Testes básicos de captura, tratamento de imagens e determinação de pontos e centróides.

2. **Complex Version**:
   - Captura e tratamento de imagens.
   - Determinação de pontos e centróides.
   - Cálculo de métricas Euclidianas e proporções métricas.
   - Registro das informações no banco de dados.

3. **Full Inspection Version - Vulcano**:
   - Captura e tratamento da imagem base.
   - Determinação de pontos e centróides para gerar um padrão de inspeção.
   - Captura e tratamento das imagens inspecionadas.
   - Cálculo de métricas Euclidianas e proporções métricas.
   - Registro das informações no banco de dados.

## Sistemas Auxiliares

- **SimulaPainel**: Simulador de painel digital para computadores.
- **EleVrPDA**: Gerador de elementos de tela para dispositivos móveis (PDA).

## Conclusão

Este projeto demonstra uma abordagem eficiente para a inspeção automatizada de segmentos de matrizes de cristal líquido, utilizando processamento de imagens e técnicas matemáticas para garantir precisão na análise. O sistema foi projetado para ser flexível, permitindo a integração com diferentes dispositivos de captura de imagem.


## Testes do Algortimo de Vizinhança e das estruturas de dados para localização de elementos na imagem

[Video do teste do algoritmo de vizinhança](https://youtu.be/JpsyqKUG5YU)

## Principais imagens do sistema

### Tela Principal do Vulcano
![Tela Principal - Sistema Vulcano](https://mdcursos.dev.br/img/sisdesk/TelaPrincipalVulcano.png)

### Tela de Parametros
![Tela de Parametros - Sistema Vulcano](https://mdcursos.dev.br/img/sisdesk/TelaParametro.png)

### Capa Livro - Resultado da Pesquisa para desenvolver o Sistema
![Capa Livro - Resultado da Pesquisa](https://mdcursos.dev.br/img/sisdesk/Capa_Livro.png)
