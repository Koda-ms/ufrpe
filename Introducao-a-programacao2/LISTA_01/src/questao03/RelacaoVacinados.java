package questao03;

import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class RelacaoVacinados {

	private ArrayList<RegistroVacina> vacinados;

	public RelacaoVacinados() {
		this.vacinados = new ArrayList<>();
	}
	
	public void adicionar(RegistroVacina registro) {
		vacinados.add(registro);
	}
	
	public double calcularTotalVacinadosAcimaDe(int idade) {
		
		int qtdCompletamenteVacinados = 0;
		for(RegistroVacina rgv : this.vacinados) {
			
			if(rgv.getVacinado().calcularIdade() > idade && rgv.getDose() == 2) {
				qtdCompletamenteVacinados++;
			}
		}
		return qtdCompletamenteVacinados;
	}
	
	public void totalDeIdososQueTomaram2aDose() {
		
		int idososCom2aDose = 0;
		for(RegistroVacina rgv : this.vacinados) {
			
			if(rgv.getGrupo() == "IDOSOS" && rgv.getDose() == 2) {
				idososCom2aDose++;
			}
		}
	}
	
	public void listarPessoasQueNaoTomaram2aDose() {
		
		System.out.printf("%-12s|%-14s|%-7s|%-24s\n", "CPF", " Nome", " Idade", " Data Indicada p. 2a Dose");
		for (int i = 0; i < 61; i++) System.out.printf("-");
		System.out.println();
		
		for(RegistroVacina rgv: this.vacinados) {
			
			if(rgv.getDose() == 1) {
				String dataFormatada = DateTimeFormatter.ofPattern("dd/MM/YYYY").format(rgv.getData_vacinacao().plusDays(21));
				
				System.out.printf("%-12s| %-13s|%6d |%25s\n",
						rgv.getVacinado().getCpf(),
						rgv.getVacinado().getNome(),
						rgv.getVacinado().calcularIdade(),
						dataFormatada);
			}
		}
		for (int i = 0; i < 61; i++) System.out.printf("-");
		System.out.println();
		
		System.out.printf("Total de vacinados acima de 65 anos: " + this.calcularTotalVacinadosAcimaDe(65));
		
		int pessoasCom2aDose = 0, pessoasSem2aDose = 0;
		for(RegistroVacina regiv: this.vacinados) {
			
			if(regiv.getDose() == 2) {
				pessoasCom2aDose++;
			} else if(regiv.getDose() == 1) {
				pessoasSem2aDose++;
			}
		}
		System.out.printf("\nTotal de vacinados que não tomaram a 2a. dose: " + pessoasSem2aDose);
		System.out.printf("\nTotal de vacinados que tomaram a 2a. dose: " + pessoasCom2aDose);

	}
}
