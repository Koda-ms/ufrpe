package questao03;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

import questao03.despesa.DespesaComAgua;
import questao03.despesa.DespesaComEnergia;
import questao03.despesa.DespesaComInternet;
import questao03.receita.LicensaBasica;
import questao03.receita.LicensaEnterprise;
import questao03.receita.LicensaPlus;

public class Empresa {

	public static void main(String[] args) {
		
		//Instancia as receitas 
		ITransacao receitaBasica = new LicensaBasica(LocalDateTime.of(2022, 3, 9, 18, 04), 
				"Licensa Básica", 12);
		ITransacao receitaEnterprise = new LicensaEnterprise(LocalDateTime.of(2022, 1, 22, 14, 58), 
				"Licensa Enterprise", 42);
		ITransacao receitaPlus = new LicensaPlus(LocalDateTime.of(2022, 1, 2, 22, 00), 
				"Licensa Plus", 103);
		
		//Instancia as despesas
		ITransacao contaNeoenergia = new DespesaComEnergia(LocalDateTime.of(2022, 3, 24, 8, 30), 
				"Conta de Luz", 50);
		ITransacao contaCompesa = new DespesaComAgua(LocalDateTime.of(2022, 1, 20, 10, 43), 
				"Conta de Água", 10);
		ITransacao contaOiFibra = new DespesaComInternet(LocalDateTime.of(2022, 1, 17, 17, 11), 
				"Conta de Internet", 20);
		
		//Instancia a empresa
		FluxoCaixa minhaEmpresa = new FluxoCaixa("Garden Co", "71.647.711/0001-09");
		
		//Execução dos métodos de FluxoCaixa
		minhaEmpresa.adicionarTransacao(receitaBasica);
		minhaEmpresa.adicionarTransacao(receitaEnterprise);
		minhaEmpresa.adicionarTransacao(receitaPlus);
		minhaEmpresa.adicionarTransacao(contaNeoenergia);
		minhaEmpresa.adicionarTransacao(contaCompesa);
		minhaEmpresa.adicionarTransacao(contaOiFibra);
		
		System.out.println("------ Fluxo de Caixa da "+minhaEmpresa.getNomeEmpresa()+" ------\n");
		System.out.printf("Total de Despesas: R$%,.2f\n", minhaEmpresa.calcularDespesas(LocalDate.of(2022, 1, 16), LocalDate.of(2022, 1, 25)));
		System.out.printf("Total de Receitas: R$%,.2f\n", minhaEmpresa.calcularReceitas(LocalDate.of(2022, 1, 1), LocalDate.of(2022, 1, 23)));
		System.out.printf("Percentual de Receitas: %,.2f%%\n", minhaEmpresa.percentualReceitasNoMes(3, 2022));
		System.out.printf("Percentual de Despesas: %,.2f%%\n", minhaEmpresa.percentualDespesasNoMes(3, 2022));
		System.out.printf("Saldo Atual da Empresa: R$%,.2f\n\n", minhaEmpresa.saldoAtual());
		
		//Imprime a lista formatada de transações no mês 
		List<ITransacao> transacoes = new ArrayList<>(minhaEmpresa.listarTransacoesNoMes(1, 2022));
		
		System.out.printf("%29s\n", "Transações");
		for (int i = 0; i < 53; i++) System.out.printf("-");
		System.out.println();
		
		//Parte referente às receitas
		System.out.printf("%-20s|%-14s|%-13s|\n", "Receitas", " Total de Contas ", " Valor");
		
		for (int i = 0; i < 53; i++) System.out.printf("-");
		System.out.println();
		for(ITransacao t : transacoes) {
			if(t.getTipo().equals("Receita")) {
				System.out.printf("%-20s| %15s | R$%,9.2f |\n",t.getDescricao(),
						t.toString(), t.calcularTotal());
			}
		}
		for (int i = 0; i < 53; i++) System.out.printf("-");
		System.out.println();
		
		//Parte referente às despesas
		System.out.printf("%-20s|%-17s|%-13s|\n", "Despesas", " Quantidade ", " Valor");
		
		for (int i = 0; i < 53; i++) System.out.printf("-");
		System.out.println();
		for(ITransacao t : transacoes) {
			if(t.getTipo().equals("Despesa")) {
				System.out.printf("%-20s| %15s | R$%,9.2f |\n",t.getDescricao(),
						t.toString(), t.calcularTotal());
			}
		}
		for (int i = 0; i < 53; i++) System.out.printf("-");
		System.out.println();
	}
}
