### Link do Jogo no itch.io
---
[Cai-Não-Cai 3D](https://sdkbinho.itch.io/cai-no-cai-3d)

### Alunos:  
Brayan  
Fábio  
Nathan  

```bash
UE="/c/Program Files/Epic Games/UE_5.8/Engine/Binaries/Win64/UnrealEditor.exe"
PROJ="$HOME/Documents/Unreal Projects/cai_nao_cai/cai_nao_cai.uproject"

alias host='"$UE" "$PROJ" "CaiNaoCaiLevel?listen" -game -log &'
join() { "$UE" "$PROJ" "$1" -game -log & }
```
