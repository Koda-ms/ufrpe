package questao03;

import java.time.LocalDate;

public class RegistroVacina {
	
	private String id;
	private LocalDate data_vacinacao;
	private String atendente;
	private int dose;
	private String local;
	private String grupo;
	private Vacina vacina;
	private Pessoa vacinado;

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public LocalDate getData_vacinacao() {
		return data_vacinacao;
	}

	public void setData_vacinacao(LocalDate data_vacinacao) {
		this.data_vacinacao = data_vacinacao;
	}

	public String getAtendente() {
		return atendente;
	}

	public void setAtendente(String atendente) {
		this.atendente = atendente;
	}

	public int getDose() {
		return dose;
	}

	public void setDose(int dose) {
		this.dose = dose;
	}

	public String getLocal() {
		return local;
	}

	public void setLocal(String local) {
		this.local = local;
	}

	public String getGrupo() {
		return grupo;
	}

	public void setGrupo(String grupo) {
		this.grupo = grupo;
	}

	public Vacina getVacina() {
		return vacina;
	}

	public void setVacina(Vacina vacina) {
		this.vacina = vacina;
	}

	public Pessoa getVacinado() {
		return vacinado;
	}

	public void setVacinado(Pessoa pessoa) {
		this.vacinado = pessoa;
	}

}
