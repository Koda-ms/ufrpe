package questao01;

import java.util.Arrays;
import java.util.Random;

public class BilheteLoteria {
	
	private int[] bilhetePremiado;

	public BilheteLoteria(int tamanhoArray) {
		this.bilhetePremiado = new int[tamanhoArray];
		Random rand = new Random();
		
		//Ir� geerar o intervalo espec�fico de valores (1-60)
		int max = 60, min = 01;
		for(int i = 0; i < this.bilhetePremiado.length; i++) {
			int nAleatorio = rand.nextInt((max - min) + 1) + min;
			this.bilhetePremiado[i] = nAleatorio;
			
			//Checa se h� n�meros repetidos. Se sim, o n�mero ser� removido
			//e outro n�mero aleat�rio e diferente ser� adicionado
			for(int j = 0; j < i; j++) {
				if(this.bilhetePremiado[j] == nAleatorio) {
					nAleatorio = rand.nextInt((max - min) + 1) + min;
					j=-1; //Isso ir� recome�ar o loop
				}
			}
			this.bilhetePremiado[i] = nAleatorio;
		}
		//Para ordenar o array
		Arrays.sort(bilhetePremiado);
	}
	
	public int qtdNumerosContidos(BilheteLoteria bilheteApostado) {
		
		if(bilheteApostado == null) {
			return 0;
		}
		int qtdNumerosIguais = 0;
		int[] numBilhete = bilheteApostado.getNumeros();
		
		for(int i = 0; i < this.bilhetePremiado.length; i++) {
			for(int j = 0; j < numBilhete.length; j++) {
				if(this.bilhetePremiado[i] == numBilhete[j]) {
					qtdNumerosIguais++;
				}
			}
		}
		return qtdNumerosIguais;
	}
	
	public int[] getNumeros() {
        return bilhetePremiado;
    }
	
	@Override
	public String toString() {
		StringBuffer buffer = new StringBuffer();
		buffer.append("[");
		
		for(int i = 0; i < this.bilhetePremiado.length; i++) {
			buffer.append(this.bilhetePremiado[i]);
			
			if(i != this.bilhetePremiado.length-1) {
				buffer.append(", ");
			}
		}
		buffer.append("]");
		return buffer.toString();
	}
}
