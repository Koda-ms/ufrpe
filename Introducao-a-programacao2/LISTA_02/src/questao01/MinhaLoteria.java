package questao01;

import java.util.ArrayList;

public class MinhaLoteria {

	public static void main(String[] args) {
		
		BilheteLoteria bilhetePremiado = new BilheteLoteria(6);
		
		//Para ver qual foi o bilhete premiado
		/*System.out.println(bilhetePremiado.toString());
		System.out.println();*/
		
		for(int i = 6; i <= 15; i++) {
			ArrayList<BilheteLoteria> bilhetes = new ArrayList<>();
			int qtdQuadras = 0, qtdQuinas = 0, qtdNumContidos = 0;
			boolean continuar = false;
			
			 do{
				BilheteLoteria bilheteSorteado = new BilheteLoteria(i);
				bilhetes.add(bilheteSorteado);
				qtdNumContidos = bilhetePremiado.qtdNumerosContidos(bilheteSorteado); 
				
				if(qtdNumContidos == 4) {
					qtdQuadras++;
				} else if(qtdNumContidos == 5) {
					qtdQuinas++;
				} else if(qtdNumContidos == 6) {
					System.out.println("Parabéns você ganhou na megasena depois de " + bilhetes.size()
							+ " tentativas de jogo! \nBilhete Sorteado: " + bilheteSorteado.toString());
					continuar = true;
				}
				//Para depuração do código
				/*System.out.println("Sorteio de número "+bilhetes.size()+" realizado. O bilhete sorteado "+bilheteSorteado.toString()+" 
					+ "NÃO CONTÉM todos os números do bilhete premiado "+bilhetePremiado.toString());*/
				
			}while(!continuar);
			System.out.println("Jogos de "+ i +" números: você apostou "+ bilhetes.size() +" vezes para ganhar na mega-sena. "
					+ "Dentre esses jogos, você acertou "+ qtdQuadras +" quadras e "+ qtdQuinas +" quinas.");
			System.out.println();
		}
	}
}
