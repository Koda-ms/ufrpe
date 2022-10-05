package questao03;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class FluxoCaixa {

	private String nomeEmpresa;
	private String cnpj;
	private List<ITransacao> transacoes;
	
	public FluxoCaixa(String nomeEmpresa, String cnpj) {
		super();
		this.nomeEmpresa = nomeEmpresa;
		this.cnpj = cnpj;
		transacoes = new ArrayList<>();
	}
	
	public List<ITransacao> getTransacoes() {
		return transacoes;
	}

	public String getNomeEmpresa() {
		return nomeEmpresa;
	}

	public void setNomeEmpresa(String nomeEmpresa) {
		this.nomeEmpresa = nomeEmpresa;
	}

	public String getCnpj() {
		return cnpj;
	}

	public void setCnpj(String cnpj) {
		this.cnpj = cnpj;
	}
	
	public void adicionarTransacao(ITransacao transacao) {
		if(transacao != null) {
			boolean transacaoJaCadastrada = false;
			
			for(ITransacao t : this.transacoes) {
				if(t.equals(transacao)) {
					transacaoJaCadastrada = true;
					System.out.println("Transação já cadastrada!");
				}
			}
			if(!transacaoJaCadastrada) {
				this.transacoes.add(transacao);
			}
		}
	}
	
	public double calcularDespesas(LocalDate inicio, LocalDate fim) {
		double totalDespesas = 0;
		
		for(ITransacao t : this.transacoes) 
		{
			if((inicio.isBefore(t.getData().toLocalDate()) && 
					(fim.isAfter(t.getData().toLocalDate()))) &&
					t.getTipo().equals("Despesa")) { //If this doesn't work, try to separate the conditions in 2
				totalDespesas += t.calcularTotal();
			}
		}
		return totalDespesas;
	}
	
	public double calcularReceitas(LocalDate inicio, LocalDate fim) {
		double totalReceitas = 0;
		
		for(ITransacao t : this.transacoes) 
		{
			if((inicio.isBefore(t.getData().toLocalDate()) && 
					(fim.isAfter(t.getData().toLocalDate()))) &&
					t.getTipo().equals("Receita")) { //If this doesn't work, try to separate the conditions in 2
				totalReceitas += t.calcularTotal();
			}
		}
		return totalReceitas;
	}
	
	public double percentualReceitasNoMes(int mes, int ano) {
		double receitasNoAno = 0, receitasNoMes = 0, percentualReceitas = 0;
		
		for(ITransacao t : this.transacoes) {
			if(t.getData().getYear() == ano && t.getTipo().equals("Receita")) {
				receitasNoAno += t.calcularTotal();
				
				if(t.getData().getMonthValue() == mes && t.getTipo().equals("Receita")) {
					receitasNoMes += t.calcularTotal();
				}
			}
		}
		percentualReceitas = (receitasNoMes / receitasNoAno) * 100;
		
		return percentualReceitas;
	}
	
	public double percentualDespesasNoMes(int mes, int ano) {
		double despesasNoAno = 0, despesasNoMes = 0, percentualDespesas = 0;
		
		for(ITransacao t : this.transacoes) {
			if(t.getData().getYear() == ano && t.getTipo().equals("Despesa")) {
				despesasNoAno += t.calcularTotal();
				
				if(t.getData().getMonthValue() == mes && t.getTipo().equals("Despesa")) {
					despesasNoMes += t.calcularTotal();
				}
			}
		}
		percentualDespesas = (despesasNoMes / despesasNoAno) * 100;
		
		return percentualDespesas;
	}
	
	public double saldoAtual() {
		double saldoDespesas = 0, saldoReceitas = 0;
		
		for(ITransacao t : this.transacoes) {
			if(t.getTipo().equals("Despesa")) {
				saldoDespesas += t.calcularTotal();
			}
			if(t.getTipo().equals("Receita")) {
				saldoReceitas += t.calcularTotal();
			}
		}
		return  saldoReceitas - saldoDespesas;
	}
	
	public List<ITransacao> listarTransacoesNoMes(int mes, int ano){
		
		List<ITransacao> transacoes = new ArrayList<>();
		for(ITransacao t : this.transacoes) {
			if(t.getData().getYear() == ano && t.getData().getMonthValue() == mes) {
				transacoes.add(t);
			}
		}
		return transacoes;
	}
}
