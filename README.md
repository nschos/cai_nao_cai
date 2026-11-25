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

---

### Build C++
Compilação do código em C++ (linha de comando)

`<OS> | Sistema operacional (Linux, Windows, macOS)`  
`<PATH_TO_PROJECT> | Caminho para o projeto`
`<PATH_TO_UNREAL> | Caminho de instalação da Unreal`

```powershell
<PATH_TO_UNREAL>/Engine/Build/BatchFiles/<OS>/Build.sh cai_nao_caiEditor <OS> Development -Project="<PATH_TO_PROJECT>/cai_nao_cai.uproject" -Progress
```

> ### Exemplo Windows
>```powershell
>& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" cai_nao_caiEditor Win64 Development -Project="C:\Users\fabio.orlandi\Documents\Unreal Projects\cai_nao_cai\cai_nao_cai.uproject" -Progress
>```
