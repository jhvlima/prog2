int *SomaVetores(int *a, int *b, int tamanho_dos_vetores){
int i;
int *resultado = (int *) malloc (tamanho_dos_vetores * sizeof(int));

for (i = 0; i < tamanho_dos_vetores; i++)
resultado[i] = a[i] + b[i];

return resultado;
}